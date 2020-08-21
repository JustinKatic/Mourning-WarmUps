#include <string>
#include <vector>
#include <iostream>
struct Point { int x; int y; };
std::vector<std::string> Explode(char separator, const char* str)
{
    std::vector<std::string> result;
    int i = 0;
    std::string substring;
    while (str[i] != '\0')
    {
        if (str[i] != separator)
        {
            substring.push_back(str[i]);
        }
        else
        {
            if (substring != "")
            {
                result.push_back(substring);
            }
            substring.clear();
        }
        i++;
    }
    if (substring != "")
    {
        result.push_back(substring);
    }
    return result;
}
std::vector<Point> ParsePointString(const std::string& sPoints)
{
    std::vector<Point>result;
    Point point;

    auto points = Explode(' ', sPoints.c_str());

    for (auto pointsToBeSep : points)
    {
        auto sepPoints = Explode(',', pointsToBeSep.c_str());
        point.x = std::stoi(sepPoints[0]);
        point.y = std::stoi(sepPoints[1]);
        result.push_back(point);
    }

    return result;
}
int main(int argc, char** argv)
{
	std::string sPoints = "0,0 -3,-214 187,-422 196,-862 -95,-1044 -461,-1219 -732,-1310 -950,-1338 -1213,-1339";
	auto points = ParsePointString(sPoints);
	for (auto& point : points)
	{
		std::cout << point.x << "\t" << point.y << std::endl;
	}
	return 0;
}