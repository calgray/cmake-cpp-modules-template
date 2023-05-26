

import boost.ut;
import fmt.core;
import stdcxx;

using namespace boost::ut;

suite bdd_suite = [] {
  bdd::gherkin::steps steps = [](auto& steps) {
    steps.feature("Vector") = [&] {
      steps.scenario("*") = [&] {
        steps.given("I have a vector") = [&] {
          std::vector<int> v(5);
          expect((5_ul == std::size(v)) >> fatal);

          steps.when("I resize bigger") = [&] {
            v.resize(10);
          };

          steps.then("The size should increase") = [&] {
            expect(10_ul == std::size(v));
          };
        };
      };
    };
  };

  "Vector"_test = steps |
    R"(
      Feature: Vector
        Scenario: Resize
          Given I have a vector
           When I resize bigger
           Then The size should increase
    )";
};
