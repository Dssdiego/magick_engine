// fragment
#version 330

out vec4 color;

void main()
{
    color = vec4(1.0, 1.0, 1.0, 1.0);
}

// vertex
#version 330

void main()
{
    gl_Position = vec4(0.0, 0.0, 0.0, 1.0);
}