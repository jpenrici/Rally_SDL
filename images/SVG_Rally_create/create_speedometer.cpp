/*
 *  Compile and run:
 *      make speedometer && ./Create_svg_speedometer
*/
#include "svg_manager.h"

#include <iostream>
#include <vector>

#define EMPTY ""

using namespace std;

vector<string> rectangle(Point center, float radius, float angle, float width,
    float length)
{
    Style st_rectangle;
    st_rectangle.set(Color(WHITE), 1.0, Color(WHITE), 0.1, 1.0);

    Point c1 = center.polar(radius, angle);
    Point p1 = c1.polar(width / 2, angle + 270);
    Point p2 = p1.polar(length   , angle + 180);
    Point p3 = p2.polar(width    , angle +  90);
    Point p4 = c1.polar(width / 2, angle +  90);

    return Polygon({p1, p2, p3, p4}, st_rectangle, EMPTY).getSvgVector();
}

vector<string> speedometer(Point origin, int size, int speed)
{
    vector<string> result, temp;

    // Scale
    vector<double> radius {
        size * 1.00,
        size * 0.48,
        size * 0.42,
        size * 0.34,
        size * 0.25,
        size * 0.08
    };

    // Center
    Point center(origin.x + size / 2, origin.y + size / 2); 

    // Circles
    vector<Style> st_circle {
        Style(Color(BLACK), Color(BLACK)),
        Style(Color("#161712"), Color(WHITE)),
        Style(Color("#5D5C59"), Color(WHITE)),
        Style(Color("#2F2F2C"), Color(WHITE)),
        Style(Color("#1A1A1C"), Color(WHITE)),
        Style(Color("#161712"), Color("#5D5C59"))
    };

    for (auto i: {1, 2, 3, 5})
    {
        temp = Circle(center,radius[i], st_circle[i],
            "Circle_radius_" + to_string(i)).getSvgVector();
        result.reserve(result.size() + temp.size());
        result.insert(result.end(), temp.begin(), temp.end());
    }

    // Indicator
    int step = 4;
    int width = 2;
    int angle_0 = 150;
    int angle_1 = 330;

    Style st_text(Color(WHITE) , Color(WHITE));
    st_text.setFont("Ubuntu");
    st_text.setSize(radius[5]);
    for (int angle = angle_0, number = 0; number <= 60; number++)
    {
        float length = (radius[1] - radius[2]) / 3;
        if (number % 10 == 0)
        {   
            length *= 3.5;
            Point ct = center.polar(radius[4], angle) + Point(-radius[5] / 2, 0);
            temp = Text(ct, to_string(number), st_text, EMPTY).getSvgVector();
            result.reserve(result.size() + temp.size());
            result.insert(result.end(), temp.begin(), temp.end());
        } 
        else
        {
            if (number % 5 == 0)
            {
                length *= 1.5;
            }
        }

        temp = rectangle(center, radius[2], angle, width, length);
        result.reserve(result.size() + temp.size());
        result.insert(result.end(), temp.begin(), temp.end());

        angle += step;
    }

    Style st_indicator;
    if (speed < 1)
    {
        st_indicator.setFill(Color(WHITE), 1.0);
        st_indicator.setStroke(Color(BLACK), 1.0, 0.5);
    }

    if (speed > 5)
    {
        st_indicator.setFill(Color(GREEN), 1.0);
        st_indicator.setStroke(Color(GREEN), 1.0, 0.5);
    }

    if (speed > 45)
    {
        st_indicator.setFill(Color(RED), 1.0);
        st_indicator.setStroke(Color(RED), 1.0, 0.5);
    }

    temp = Circle(center.polar(radius[4] / 2, 270), radius[5] * 0.4, 
        st_indicator, EMPTY).getSvgVector();
    result.reserve(result.size() + temp.size());
    result.insert(result.end(), temp.begin(), temp.end());  

    // Pointer
    temp = rectangle(center, radius[5], angle_1 + speed * step, width, radius[1]);
    result.reserve(result.size() + temp.size());
    result.insert(result.end(), temp.begin(), temp.end());

    return result;
}

int main()
{
    float frame = 128;

    // SVG
    SVG imageSVG("../SVG_Base/speedometer-animate-alpha.svg",
        10 * frame, 7 * frame);

    float x = 0;
    float y = 0;
    for (int i = 0, speed = 0; speed <= 60; speed++)
    {   
        imageSVG.add(speedometer(Point(x, y), frame, speed));

        x += frame;
        if (i++ == 9)
        {
            y += frame;
            x = 0;
            i = 0;
        }
    }
    
    imageSVG.background(false);
    imageSVG.make();
    imageSVG.save();

    return 0;
}
