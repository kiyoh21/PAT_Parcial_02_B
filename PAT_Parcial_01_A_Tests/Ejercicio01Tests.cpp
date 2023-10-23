#include "pch.h"

#include <tuple>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

#include "../PAT_Parcial_01_A/Ejercicio01.h"
#include "../PAT_Parcial_01_A/Node.h"

using ::testing::TestWithParam;
using ::testing::ValuesIn;
using ::std::tuple;
using ::std::vector;
using ::std::string;

namespace P02Tests {
	class E01Tests : public TestWithParam<tuple<vector<char>, vector<char>>> {
	protected:
		Ejercicio01* e01;
		vector<char> params;
		vector<char> expected;
		
		void SetUp() override {
			e01 = new Ejercicio01();
			std::tie(params, expected) = GetParam();
		}

		void TearDown() override {
			delete e01;
			e01 = nullptr;
		}

	public:

		static vector<tuple<vector<char>, vector<char>>> ReadParams() {
			vector<tuple<vector<char>, vector<char>>> params;

			std::ifstream paramsFile("e01.csv");
			string line;

			while (std::getline(paramsFile, line)) {
				std::stringstream strStream(line);

				string paramsString;
				std::getline(strStream, paramsString, ',');
				vector<char> p(paramsString.begin(), paramsString.end());

				string expectedString;
				std::getline(strStream, expectedString, ',');
				vector<char> e(expectedString.begin(), expectedString.end());

				params.push_back(tuple<vector<char>, vector<char>>(p, e));
;			}

			return params;
		}
	};

	Node<char>* buildList(vector<char>& params) {
		Node<char>* head = nullptr;
		Node<char>** it = &head;
		
		for (char c : params) {
			*it = new Node<char>{c};
			it = &((*it)->next);
		}

		return head;
	}

	vector<char> buildFromList(Node<char>* head) {
		vector<char> result;

		Node<char>* it = head;

		while (it) {
			result.push_back(it->value);
			it = it->next;
		}

		return result;
	}

	TEST_P(E01Tests, E01RemovingValues) {
		Node<char>* head = buildList(params);
		Node<char>* expectedHead = buildList(expected);

		head = e01->remove(head);

		vector<char> actual = buildFromList(head);

		int i = 0;
		while (head && expectedHead) {
			ASSERT_EQ(expectedHead->value, head->value) << "Error en la posicion [" << i << "] de la lista"
				<< ". Se esperaba [" << expectedHead->value << "], pero se encontro [" << head->value
				<< "]\nLista esperada: [" << string(expected.begin(), expected.end()) << "]\nLista obtenida: [" << string(actual.begin(), actual.end()) << "]";

			head = head->next;
			expectedHead = expectedHead->next;
			++i;
		}

		EXPECT_TRUE(head == nullptr && expectedHead == nullptr) << "La cantidad de nodos no es la esperada."
			<< "\nLista esperada: [" << string(expected.begin(), expected.end()) << "]\nLista obtenida: [" << string(actual.begin(), actual.end()) << "]";
	}

	INSTANTIATE_TEST_CASE_P(E01RemovingValues, E01Tests, ValuesIn(E01Tests::ReadParams()));
}