#version 330 core

layout (location = 0) out vec4 color;

uniform vec3 player_pos;
uniform vec3 light_pos;
uniform sampler2D tex;

in DATA {
    vec3 position;
    vec3 normal;
    vec2 tc;
	vec4 color;
} fs_in;


void main() {
	float intensity = clamp(dot((-fs_in.normal), normalize(fs_in.position - light_pos)), 0, 1);
	vec4 texColor = fs_in.color;
	texColor = texture(tex, fs_in.tc);
	color = texColor;
}