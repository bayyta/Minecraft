#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 tc;
layout (location = 4) in vec4 color;

uniform mat4 pr_matrix = mat4(1.0);
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 ml_matrix = mat4(1.0);

out DATA {
    vec4 position;
    vec3 normal;
    vec2 tc;
	vec4 color;
} vs_out;

void main() {
    gl_Position = pr_matrix * vw_matrix * ml_matrix * position;
    vs_out.position = vec4(pr_matrix * vw_matrix * ml_matrix * position);
    vs_out.normal = vec3(ml_matrix * vec4(normal, 0.0));
    vs_out.tc = tc;
	vs_out.color = color;
}