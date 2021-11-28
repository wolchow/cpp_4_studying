#include <iostream>
#include <limits>
#include <vector>

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
};

class Max : public IStatistics {
public:
	Max() : m_max{std::numeric_limits<double>::min()} {
	}

	void update(double new_) override {
		if (new_ > m_max) {
			m_max = new_;
		}
	}

	double eval() const override {
		return m_max;
	}

	const char * name() const override {
		return "max";
	}

private:
	double m_max;

};

class Mean : public IStatistics	{
public:
	int cnt = cnt_;
	double sum = sum_;
	double mean = mean_;

	Mean() : cnt_ {0}, sum_ {0.0}, mean_ {0.0} {};

	void update(double new_) override {
		sum_ += new_;
		cnt_+=1;
		mean_ = cnt_ > 1 ? sum_/cnt_ : sum_;
	}

	double eval() const override {
		return mean_;
	}

	const char * name() const override {
		return "mean";
	}

private:
	double sum_;
	int cnt_;
	double mean_; // I suppose due to const limitation in base class eval()
};

class Deviation : public IStatistics {
public:
	Deviation() : cnt_ {0}, sum_ {0.0}, mean_ {0.0}, dev_ {0.0} {};

	void update(double new_) override {
		lst.push_back(new_);
		sum_ += new_;
		cnt_+=1;
		mean_ = cnt_ > 1 ? sum_/cnt_ : sum_;
		recalc();	
	}

	double eval() const override {
		return dev_;
	}

	const char * name() const override {
		return "dev";
	}

private:
	std::vector<int> lst {};
	int cnt_;
	double sum_;
	double mean_;
	double dev_;

	//I don't like the implementation below which needs to be called each update(), but eval() const requires this
	void recalc() {
		double sq = 0.0;
		for (size_t i = 0; i < lst.size(); ++i) {
			sq += std::pow((lst[i] - mean_), 2);
		}
		dev_ = std::sqrt(sq/(cnt_ > 1 ? cnt_ - 1 : 1));
	}

};

int main() {

	const size_t statistics_count = 4;
	IStatistics *statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new Deviation{};

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}