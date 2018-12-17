#version 130
uniform sampler2D texture;
uniform vec2 iResolution;

in vec2 tex_coord;

void main()
{
    vec2 norm = vec2(gl_FragCoord.x/iResolution.x, gl_FragCoord.y/iResolution.y); 
    gl_FragColor = texture2D(texture, norm);
}
