#version 330 core

out vec4 FragColor;
in vec2 TextureCoords;

// texture sampler
uniform sampler2D texture1;
uniform vec4 RGBA;
uniform bool changeColor;

void main()
{
       if(changeColor){
       FragColor = mix(texture(texture1 , TextureCoords) , RGBA , 0.3f);
       }
       else{
       FragColor = texture(texture1 , TextureCoords);
       }
   
}
