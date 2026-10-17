struct VSInput{
	float3 position : POSITION;
	float3 normal : NORMAL;
	float2 uv : TEXCOORD;
};

struct PSInput{
	float3 position : SV_Position;
	float3 normal : NORMAL;
};

PSInput VSMain(VSInput input)
{
	PSInput output;

	output.position = mul(mvp, float4(input.position, 1));
	output.normal = input.normal;

	return output;
}

float4 PSMain(PSInput input) : SV_Target
{
	float l = saturate(dot(normalize(input.normal), normalize(float3(1, 1, -1))));
	return float4(l.xxx * 0.8 + 0.1, 1);
}