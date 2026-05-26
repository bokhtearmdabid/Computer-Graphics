/*
 * Interactive Graphics Clock System
 *
 * Algorithms used:
 *   - Bresenham's Line Drawing Algorithm  (clock hands & tick marks)
 *   - Midpoint Circle Drawing Algorithm   (clock face circles)
 *   - GLUT Timer                          (real-time animation)
 *
 * Compile (Linux/macOS):
 *   gcc clock.c -o clock -lGL -lGLU -lglut -lm
 *
 * Compile (Windows – MinGW + FreeGLUT):
 *   gcc clock.c -o clock.exe -lfreeglut -lopengl32 -lglu32 -lm
 *
 * Press ESC to exit.
 */

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

/* ───────────────────────────────────────────────
   Window & coordinate settings
   World space: 0..640 x 0..640
   Clock centre: (320, 320)
─────────────────────────────────────────────── */
#define WIN_SIZE   640
#define CX         320      /* clock centre x */
#define CY         320      /* clock centre y */

/* ── Radii ── */
#define R_GLOW      230
#define R_BEZEL1    220
#define R_FACE      210
#define R_BEZEL2    195
#define R_TICK_OUT  188
#define R_HTICK_IN  172     /* hour tick inner end   */
#define R_MTICK_IN  180     /* minute tick inner end */
#define R_NUMERAL   155     /* numeral placement     */

/* ── Hand lengths ── */
#define LEN_HOUR     100
#define LEN_MIN      138
#define LEN_SEC      155
#define LEN_BACK      28    /* tail behind centre    */

/* ═══════════════════════════════════════════════
   main
═══════════════════════════════════════════════ */
int main(int argc, char **argv)
{
    /* Read initial time */
    time_t     now = time(NULL);
    struct tm *t   = localtime(&now);
    g_hour = t->tm_hour;
    g_min  = t->tm_min;
    g_sec  = t->tm_sec;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIN_SIZE, WIN_SIZE);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Interactive Graphics Clock | Bokhtear MD Abid");

    myInit();
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
