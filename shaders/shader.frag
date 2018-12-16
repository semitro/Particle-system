#version 130
uniform sampler2D texture;
in vec2 tex_coord;

void main()
{
    gl_FragColor = vec4(0.5, 0.1, 0.2, 1.);//texture2D(texture, gl_FragCoord.yx/2400);
}
