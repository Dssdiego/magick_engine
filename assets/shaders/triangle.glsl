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
    if (gl_VertexID == 0)
        gl_Position = vec4(0.25, -0.25, 0.0, 1.0);
    else if (gl_VertexID == 1)
        gl_Position = vec4(-0.25, -0.25, 0.0, 1.0);
    else
        gl_Position = vec4(0.0, 0.25, 0.0, 1.0);
}