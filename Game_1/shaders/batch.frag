#version 330 core

layout (location = 0) out vec4 color;

uniform vec3 player_pos;
uniform vec3 light_pos;
uniform sampler2D textures[32];

in DATA {
    vec3 position;
    vec3 normal;
    vec2 tc;
	vec4 color;
	float tid;
} fs_in;


void main() {
	float intensity = clamp(dot((-fs_in.normal), normalize(fs_in.position - light_pos)), 0, 1);
	vec4 texColor = fs_in.color;
	if (fs_in.tid > 0.0)
	{
		int tid = int(fs_in.tid - 0.5);
		texColor = texture(textures[tid], fs_in.tc);
	}

	color = vec4(texColor.r, texColor.g, texColor.b, 1.0);
}