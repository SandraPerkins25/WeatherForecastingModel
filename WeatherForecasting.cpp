#include <iostream>
#include <random>

class WeatherForecast {
public:
    WeatherForecast() {
        std::random_device rd;
        rng_.seed(rd());
    }

    std::string forecast(int days) {
        std::string forecast = "";
        std::uniform_int_distribution<int> dist(0, 1);
        for (int i = 0; i < days; i++) {
            int chance_of_rain = dist(rng_);
            forecast += "Day " + std::to_string(i + 1) + ": ";
            if (chance_of_rain == 0) {
                forecast += "Sunny\n";
            } else {
                forecast += "Rainy\n";
            }
        }
        return forecast;
    }

private:
    std::mt19937 rng_;
};

int main() {
    WeatherForecast forecast;
    std::cout << forecast.forecast(5) << std::endl;
    return 0;
}
