#version 460 core
out vec4 FragColor;

layout (location = 0) in vec2 fragCoord;

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

float circle(float radius, vec2 position, float blurPct) {
    vec2 st = fragCoord.xy/u_resolution;
    vec2 stToPos = st - position;
    float d = dot(stToPos, stToPos) * 4.0;
    float d2 = radius * blurPct;
    return smoothstep(d-d2, d+d2, radius);
}

void main() {
    vec2 st = fragCoord.xy/u_resolution;
    st.x *= u_resolution.x/u_resolution.y;
    st = (st * vec2(2.)) - vec2(1.0);

    // a. The distance from the pixel to the center
    float radius = 0.3;
    float blur = 0.01;
    vec2 position = vec2(0.33, 0.72);
    float anim = sin(u_time * 10.0) / 100.0;
    float c1 = circle(radius + anim, position, blur);
    vec3 color1 = vec3(1.0,0.399,0.843);

    float radius2 = 0.15;
    vec2 position2 = vec2(.74, .31);
    float anim2 = sin(u_time * 10.0 + 5.0) / 100.0;
    float c2 = circle(radius2 + anim2, position2, blur);
    vec3 color2 = vec3(1.0,.654,.448);

    vec3 color = vec3((c1 * color1) + (c2 * color2));

    FragColor = vec4(color, 1.0);
}