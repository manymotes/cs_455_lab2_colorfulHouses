#version 330 core
layout (location = 0) in vec3 position;
uniform mat4 transformation;
uniform mat4 scale;
uniform vec3 colorChange;
layout (location = 1) in vec3 aColor;
//layout(location = 1) in vec3 color;
out vec3 colorOut;

void main()
{
    //this gets vect 3 to vector 4
   // gl_Position = vec4(position, 1.0);
    gl_Position = transformation * vec4(position, 1.0);
    //vec3 tempColor = ;
    colorOut = aColor + colorChange;
    
    //change the color like the postion was chagned
    
}

/*
in in a vertex shader is a vertex atribute
 pass the color for the vect shader
 load in the color vector attribute from c++ into vertex array object (slides)
 
 modify colors some what via a uniform to change the colors between each array.
 
 scale add to exsiting transformation matrices. 
 
 make sure i know how to pass data from vertex shader to fragment shader.

*/
