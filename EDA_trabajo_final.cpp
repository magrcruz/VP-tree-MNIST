// Copyright 2020 Roger Peralta Aranibar Advanced Data Estructures
#include "EDA_trabajo_final.h"
#include <iomanip>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include <bitset>
#include <chrono>

#define Image bitset<784>
using namespace std;

template <typename>
class Timer;

template <typename R, typename... T>
class Timer<R(T...)> {
public:
	typedef R(*function_type)(T...);
	function_type function;

	explicit Timer(function_type function, std::string process_name = "")
		: function_(function), process_name_(process_name) {}

	R operator()(T... args) {
		std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
		start = std::chrono::high_resolution_clock::now();

		R result = function_(std::forward<T>(args)...);

		end = std::chrono::high_resolution_clock::now();
		int64_t duration =
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
			.count();

		std::cout << std::setw(10) << process_name_ << std::setw(30)
			<< "Duration: " + std::to_string(duration) + " ns\n";
		return result;
	}

private:
	function_type function_;
	std::string process_name_;
};

VPTree G_DS;

int build_data_structure() {
	return G_DS.buildVPTree();
}

std::vector<Image> knn_query(Image query, int k) {
	vector<Image> img(k);
	G_DS.knn(query, k, img);
	return img;
}

int main() {
	Timer<int()> timed_built(build_data_structure, "Index");
	timed_built();

	Timer<std::vector<Image>(Image, int)> timed_query(
		knn_query, "Query KNN");
	string consulta = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001100000001100000000000000000110000000110000000000000000111000000011100000000000000011100000001110000000000000011110000000111000000000000001110000000111100000000000001110000000011110000000000000111000000011110000000000000111000000001110000000000000011100000000111000000000000001111000000111100000000000000011111111111110000000000000001111111111111000000000000000001111100111000000000000000000000000011110000000000000000000000001110000000000000000000000000111000000000000000000000000011100000000000000000000000001110000000000000000000000000110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	Image query(consulta);

	int k = 10;
	std::vector<Image> result = timed_query(query, k);

	//printImages(result);
}