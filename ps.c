#include "ps.h"
#include <string.h>
#include <stdio.h>
// #include <stdlib.h>



void WriteEntete(File *f, Point2 dimention);
void WriteFooter(FILE *f);
void CloseFile(FILE *f);
void WriteFill(FILE *f);
void WriteMoveto(FILE *f, Point2 a);
void WriteLineto(FILE *f, Point2 a);
void WriteCurveto2(FILE *f, Point2 a, Point2 b, Point2 c);
void WriteCurveto3(FILE *f, Point2 a, Point2 b, Point2 c, Point2 d);
FILE *OpenFile(char *name);



void PsSimpleSegment(Liste *contours, Point2 dimention char *name)
{
    FILE *f = OpenFile(name);
    WriteEntete(f, dimention);

    for (size_t i = 0; i < ListeSize(contours); i++)
    {
        Tableau *tab = ListeGet(contours, i);

        WriteMoveto(f, TableauGetPoint2(tab, 0));

        for (size_t j = 1; j < TableauGetSize(tab) + 1; j++)
        {
            WriteLineto(f, TableauGetPoint2(tab, j));
        }

        WriteFill(f);
    }

    WriteFooter(f);

    CloseFile();
}
void WriteFooter(FILE *f)
{
    fprintf(f, "showpage\n");
}

void CloseFile(FILE *f)
{
    fclose(f);
}

void WriteFill(FILE *f)
{
    fprintf(f, "fill\n");
}

void WriteMoveto(FILE *f, Point2 a)
{
    fprintf("%d %d moveto\n", GetValuePoint2(a, 'x'), GetValuePoint2(a, 'y'));
}

void WriteLineto(FILE *f, Point2 a)
{
    fprintf(f, "%d %d lineto\n", GetValuePoint2(a, 'x'), GetValuePoint2(a, 'y'));
}

void WriteCurveto2(FILE *f, Point2 a, Point2 b, Point2 c)
{
    fprintf(f, "%d %d %d %d %d %d curveto\n",
            GetValuePoint2(a, 'x'), GetValuePoint2(a, 'y'),
            GetValuePoint2(b, 'x'), GetValuePoint2(b, 'y'),
            GetValuePoint2(c, 'x'), GetValuePoint2(c, 'y'));
}

void WriteCurveto3(FILE *f, Point2 a, Point2 b, Point2 c, Point2 d)
{
    fprintf(f, "%d %d %d %d %d %d %d %d curveto\n",
            GetValuePoint2(a, 'x'), GetValuePoint2(a, 'y'),
            GetValuePoint2(b, 'x'), GetValuePoint2(b, 'y'),
            GetValuePoint2(c, 'x'), GetValuePoint2(c, 'y'),
            GetValuePoint2(d, 'x'), GetValuePoint2(d, 'y'));
}

FILE *OpenFile(char *name)
{
    strcat(name, ".eps");
    FILE *f = fopen(name, 'w');
}

void WriteEntete(File *f, Point2 dimention)
{
    fprintf(f, "%%!PS-Adobe-3.0 EPSF-3.0\n");
    fprintf(f, "%%%%BoundingBox: 0 %u 0 %u\n", GetValuePoint2(dimention, 'x'), GetValuePoint2(dimention, 'y'));
}