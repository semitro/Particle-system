#version 130
uniform sampler2D texture;
uniform sampler2D baseTexture;

uniform vec2 iResolution;
uniform float uTime;

in vec2 tex_coord;

vec4 blend(vec4 bottom, vec4 top)
{
        //Overlay
//        float r = (top.r + bottom.r <1)? (0) : (top.r + bottom.r - 1);
//        float g = (top.g + bottom.g <1)? (0) : (top.g + bottom.g - 1);
//        float b = (top.b + bottom.b <1)? (0) : (top.b + bottom.b - 1);
//        return  vec4(r,g,b,bottom.a);

        //Classic color burn
        //return vector(bottom.rgb + top.rgb - 1, bottom.a);

        //Color burn
//        return vec4( 1.f - (1.f-bottom.rgb)/top.rgb, bottom.a);

        //Linear light
        float r = (top.r < 0.5f) ? (bottom.r + 2.f*top.r - 1.f) : (bottom.r + top.r);
        float g = (top.g < 0.5f) ? (bottom.g + 2.f*top.g - 1.f) : (bottom.g + top.g);
        float b = (top.b < 0.5f) ? (bottom.b + 2.f*top.b - 1.f) : (bottom.b + top.b);

        return  vec4(r,g,b,bottom.a);
}

void main()
{
    vec2 norm = vec2(gl_FragCoord.x/iResolution.x, gl_FragCoord.y/iResolution.y);
    // vec4(sin(uTime), sin(uTime), 1., 1.)

     gl_FragColor = blend(texture2D(baseTexture, norm), texture2D(texture, norm));
}
