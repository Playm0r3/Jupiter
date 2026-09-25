struct VSInput
{
	float3 position : POSITION;
	float4 color : COLOR;
};

struct VSOutput
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
};

cbuffer TransformBuffer : register(b0)
{
	float4x4 worldViewProj;
};

VSOutput VSMain(VSInput input)
{
	VSOutput output;

	output.position = float4(input.position, 1.0);
	output.color = input.color;

	return output;
}

float4 PSMain(VSOutput input) : SV_TARGET
{
	return input.color;
}