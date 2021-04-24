/*
 *  Compile and run:
 *      make speedometer && ./Create_svg_speedometer
*/
#include "svg_manager.h"
#include "counter.h"

#include <iostream>
#include <vector>

#define EMPTY ""

using namespace std;

vector<string> ometer(Point origin, int width, int height, vector<int> number)
{
    vector<string> result, temp;
    int digits = number.size();

    Style st_digits;
    Style st_text;
    st_text.setFont("Ubuntu");
    st_text.setSize(height * 0.7);    

    for(int i = 0; i < digits; i++)
    {
	    if (i < digits - 1)
	    {
	        st_digits.setFill(Color(BLACK), 1.0);
	        st_digits.setStroke(Color(BLACK), 1.0, 3.0);

	        st_text.setFill(Color(WHITE), 1.0);
	        st_text.setStroke(Color(WHITE), 1.0, 0.2);
	    }
	    else
	    {
	        st_digits.setFill(Color(WHITE), 1.0);
	        st_digits.setStroke(Color(BLACK), 1.0, 3.0);

	        st_text.setFill(Color(RED), 1.0);
	        st_text.setStroke(Color(RED), 1.0, 0.2);	                
	    }

	    temp = Rectangle(origin, width, height, 0, 0, st_digits,
	    	EMPTY).getSvgVector();
	    result.reserve(result.size() + temp.size());
	    result.insert(result.end(), temp.begin(), temp.end());

	    temp = Text(origin + Point(width / 4, height - height / 4),
	    	to_string(number[i]), st_text, EMPTY).getSvgVector();
	    result.reserve(result.size() + temp.size());
	    result.insert(result.end(), temp.begin(), temp.end());   

	    origin = origin + Point(width, 0);
	}

    return result;
}

int main()
{
    int digits = 3;
    int width = 10;
    int height = 16;
    int max = 505;

    int frame_x = width * digits + 4;
    int frame_y = height + 4;

    // SVG
    SVG imageSVG("../SVG_Base/odometer-animate-alpha.svg", 10 * frame_x,
    	(max / 10 * frame_y) + frame_y);    

   	float x = 2;
    float y = 2;

    Counter counter(digits, 0, 9, 0);
    for (int i = 0, j = 0; j <= max; ++j) {
        imageSVG.add(ometer(Point(x, y), width, height, counter.numbers()));
       	cout << counter.view() << '\n';
        counter.add();        
        x += frame_x;
        if (i++ >= 9)
        {
        	y += frame_y;
        	x = 2;
        	i = 0;
        }
    }

    imageSVG.background(false);
    imageSVG.make();
    imageSVG.save();

    return 0;
}
