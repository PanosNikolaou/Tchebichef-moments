#define MAX_WIDTH_IMSIZE    256
#define MAX_HEIGHT_IMSIZE   256
#define MAX_ORDER           100


typedef struct
{
    int   F[MAX_WIDTH_IMSIZE][MAX_HEIGHT_IMSIZE];
    int   ImWidth;
    int   ImHeight;
}Image;

//Global Declarations
Image InputImage;
int Order,N,M;

//Function Prototypes
void MainProcess(void);
void ProgressBarConfig(void);
double Bhta(int n,int N);
double p_norm(int n,int N);
double Tchebichef_bar_poly(int order,int xy,int dim);





 