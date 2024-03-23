//
// Created by Roman on 3/23/2024.
//

#include "headers.h"
#include "TriFanExample.h"

#define NUM_VERTICES 200
#define RADIUS 0.8f
#define AMP 0.05f
#define COLORS_STEP 30

struct FanColor {
    float _r, _g, _b;

    void Set(float r, float g, float b) {
        _r = r;
        _g = g;
        _b = b;
    }
};

struct FanVertex {
    float _x, _y;
    FanColor _color;

    void Set(float x, float y, float r, float g, float b) {
        _x = x;
        _y = y;
        _color.Set(r, g, b);
    }

    void SetPos(float x, float y) {
        _x = x;
        _y = y;
    }
};

static FanColor colors[] = {
        {0.5, 0, 0.5},
        {0, 1, 0},
};

static int numColors = sizeof(colors) / sizeof(FanColor);

static FanVertex vertexes[NUM_VERTICES];

bool TriFanExample::Init() {

    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);

    vertexes[0].Set(0, 0, 1, 1, 0);
    return true;
}

static float phase = 0;
static float phase2 = 0;

void TriFanExample::Update(float deltaTime) {

    phase -= deltaTime * 4;
    phase2 += deltaTime * 4;

    float angle = 0;
    float step = 360.0 / (NUM_VERTICES - 2);
    for (int i = 1; i < NUM_VERTICES; i++) {

        auto amp = AMP * sinf(float(i) * (float) M_PI * 32 / float(NUM_VERTICES - 2) + phase);
        amp += AMP * sinf(float(i) * (float) M_PI * 6 / float(NUM_VERTICES - 2) + phase2);

        auto rad = float(angle * M_PI / 180.0f);
        float x = (amp + RADIUS) * sinf(rad);
        float y = (amp + RADIUS) * cosf(rad);
        angle += step;

        vertexes[i].SetPos(x, y);
        vertexes[i]._color = colors[int(float(i) / COLORS_STEP) % numColors];
    }
    vertexes[1]._color = vertexes[NUM_VERTICES - 1]._color;

    glVertexPointer(2, GL_FLOAT, sizeof(FanVertex), &vertexes->_x);
    glColorPointer(3, GL_FLOAT, sizeof(FanVertex), &vertexes->_color);

    glDrawArrays(GL_TRIANGLE_FAN, 0, NUM_VERTICES);
}
