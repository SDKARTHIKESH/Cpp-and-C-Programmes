#include <stdio.h>

void Menu();
int Choice();

int Cube(int Edge);
int Cuboid(int Length, int Breadth, int Height);
double Sphere(int Radius);
double Cylinder(int Radius, int Height);
double Cone(int Radius, int Height);

int main(){

    Menu();
    int Option=Choice();

    while(Option!=6){

        switch(Option){

            int Edge, Length, Breadth, Height, Radius;

            case 1:

            printf("Enter the Length of the Edge of the Cube : ");
            scanf("%d", &Edge);

            printf("\n");

            printf("The Volume of the Cube is : %d", Cube(Edge));
            
            break;

            case 2:

            printf("Enter the Length of the Cuboid : ");
            scanf("%d", &Length);

            printf("Enter the Breadth of the Cuboid : ");
            scanf("%d", &Breadth);

            printf("Enter the Height of the Cuboid : ");
            scanf("%d", &Height);

            printf("\n");

            printf("The Volume of the Cuboid is : %d", Cuboid(Length, Breadth, Height));
            
            break;

            case 3:

            printf("Enter the Length of the Radius of the Sphere : ");
            scanf("%d", &Radius);

            printf("\n");

            printf("The Volume of the Sphere is : %lf", Sphere(Radius));
            
            break;

            case 4:

            printf("Enter the Length of the Radius of the Cylinder : ");
            scanf("%d", &Radius);

            printf("Enter the Height of the Cylinder : ");
            scanf("%d", &Height);

            printf("\n");

            printf("The Volume of the Sphere is : %lf", Cylinder(Radius, Height));
            
            break;

            case 5:

            printf("Enter the Length of the Radius of the Cone : ");
            scanf("%d", &Radius);

            printf("Enter the Height of the Cone : ");
            scanf("%d", &Height);

            printf("\n");

            printf("The Volume of the Sphere is : %lf", Cone(Radius, Height));
            
            break;

            default:

            printf("Enter a Valid Option!!!");

        }

        printf("\n\n");

        Menu();
        Option=Choice();

    }

}

void Menu(){

    printf("Choose one of the Following Options : \n\n");

    printf("1. Volume of Cube\n");
    printf("2. Volume of Cuboid\n");
    printf("3. Volume of Sphere\n");
    printf("4. Volume of Cylinder\n");
    printf("5. Volume of Cone\n");
    printf("6. Exit\n\n");

    return;

}

int Choice(){

    int Num;

    printf("Enter the Choice : ");
    scanf("%d", &Num);

    printf("\n");

    return Num;

}

int Cube(int Edge){

    return Edge*Edge*Edge;

}

int Cuboid(int Length, int Breadth, int Height){

    return Length*Breadth*Height;

}

double Sphere(int Radius){

    return (4*3.1415*Radius*Radius*Radius)/3;

}

double Cylinder(int Radius, int Height){

    return 3.1415*Radius*Radius*Height;

}

double Cone(int Radius, int Height){

    return Cylinder(Radius, Height)/3;

}