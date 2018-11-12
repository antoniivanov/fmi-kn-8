#include <iostream>

/*
Levenshtein distance is rather famous algorithm.
Example uses are  spell checking, speech recognition, DNA analysis (RNA/DNA sequencing), plagiarism detection.
E.g for example one follow-up exercise can be to create a little spell-checker: if entered word isn’t in the dictionary,
return the dictionary word that is closest.

Given 2 strings find the minimum number of edits (deletions, insertions, or substitutions) 
required to transform one into the other
Example see image : https://tinyurl.com/ychwz8kg
*/
int get_edit_distance(const char left_name[], const char right_name[]) {
    // we keep in distance[I][J] current min distance between left_name[0 to J - 1] and right_name[0 to J - 1]
    // hence distinance[0][2] is the distnace between empty string and the first 2 charecter from right name (right_name[0] and right_name[1])!
    int distance[128][128];

    int left_name_size = strlen(left_name);
    int right_name_size = strlen(right_name);

    // nmum edit distance between empty string and string with length N is always N (N insertions required to transform)
    for (int left_index = 0; left_index < left_name_size; ++left_index) {
        distance[left_index][0] = left_index;
    }
    for (int right_index = 0; right_index < right_name_size; ++right_index) {
        distance[0][right_index] = right_index;
    }

    for (int left_index = 0; left_index < left_name_size; ++left_index) {
        for (int right_index = 0; right_index < right_name_size; ++right_index) {
            int distance_after_substitution;

            // consider all three  operations on last character of left string 
            // try substitution:
            if (left_name[left_index] == right_name[right_index]) {
                // if both current letters match then we are fine and no substitution is required hence adding nothing
                distance_after_substitution = distance[left_index][right_index];
            } else {
                // letters do NOT match hence we need to do 1 substitution (adding 1 to previous distance)
                distance_after_substitution = distance[left_index][right_index] + 1;
            }

            // try insertion from left (cost is 1 - distance is increased with 1)
            int distance_after_left_deletion = distance[left_index][right_index + 1] + 1;
            // try deletion from left (cost is 1 - distance is increased with 1)
            int distance_after_left_insertion = distance[left_index + 1][right_index] + 1;

            // tested all 3 options pick which one produces smallest distance
            distance[left_index + 1][right_index + 1] = std::min(distance_after_substitution, 
                                                    std::min(distance_after_left_insertion, distance_after_left_deletion));
        }
    }
    return distance[left_name_size][right_name_size];
}

int main() {
    char colleague1[128];
    char colleague2[128];
    std::cin.getline(colleague1, sizeof(colleague1));
    std::cin.getline(colleague2, sizeof(colleague2));

    std::cout << get_edit_distance(colleague1, colleague2) << std::endl;
}