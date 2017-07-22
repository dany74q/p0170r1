namespace P0170R0 {

// Simple usage of constexpr (compile-time) lambdas
auto monoid = [](auto value) constexpr {
	return [=]() {
		return value;
	};
};

// 'Lazy' multiplication
auto multiply = [](auto monoidVal1) constexpr {
	return[=](auto monoidVal2) constexpr {
		return[=]() constexpr {
			return monoidVal1() * monoidVal2();
		};
	};
};

}

int main() {
	using namespace P0170R0;

	auto constexpr six = monoid(6);
	auto constexpr eight = monoid(8);
	auto constexpr fortyEight = monoid(48);

	static_assert(multiply(six)(eight)() == fortyEight(), "Should be 48");
}