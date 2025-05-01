#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;
in vec2 Texture;
  
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

uniform sampler2D image;
uniform int activeLight;

void main()
{
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    // Texture color (sample from the texture)
    vec3 textureColor = texture(image, Texture).rgb;

    vec3 result = vec3(0.0);

    if (activeLight == 1) {
        result = ambient * textureColor;
    } else if (activeLight == 2) {
        result = (ambient + diffuse) * textureColor;
    } else if (activeLight == 3) {
        result = (ambient + diffuse + specular) * textureColor;
    }

    FragColor = vec4(result, 1.0);
}