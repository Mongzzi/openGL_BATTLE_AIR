

#define WINDOW_SIZE_WIDTH 1240
#define WINDOW_SIZE_HEIGHT 800



// �ػ� ( ȭ�� ũ�� )
typedef struct _tagResolution
{
	float iW;
	float iH;

}RESOLUTION, * PRESOLUTION;


typedef enum RENDER_TYPE
{
	LINE,
	LINE_LOOP,
	TRIANGLES
}RENDER_TYPE, * PRENDER_TYPE;
