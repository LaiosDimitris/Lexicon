#include "Catch2/Catch2.hpp"
#include "../Lexicon/Lexicon.hpp"
#include <iostream>

// 1. Nα εμφανίζει το πλήθος και εφόσον ο χρήστης επιθυμεί όλες τις λέξεις 
// που έχουν το πλήθος γραμμάτων που θα δίνει ο χρήστης.
TEST_CASE("Get words with length of 4 characters")
{
    Lexicon lexicon("Test_1.txt");

    std::cout << "Get words with length of 4 characters" << std::endl;
    REQUIRE(lexicon.length(4, true) == 4);
}

// 2. Nα εμφανίζει το πλήθος και εφόσον ο χρήστης επιθυμεί όλες τις λέξεις 
// που ξεκινούν με μια ακολουθία γραμμάτων που θα δίνει ο χρήστης.
TEST_CASE("Get words that start with 'fa'")
{
    Lexicon lexicon("Test_2.txt");
    
    std::cout << "Get words that start with 'fa'" << std::endl;
    REQUIRE(lexicon.startswith("fa", true) == 20);
}

// 3. Nα εμφανίζει το πλήθος και εφόσον ο χρήστης επιθυμεί όλες τις λέξεις
// που τελειώνουν με μια ακολουθία γραμμάτων που θα δίνει ο χρήστης.
TEST_CASE("Get words that end with 'on'")
{
    Lexicon lexicon("Test_3.txt");

    std::cout << "Get words that end with 'on'" << std::endl;
    REQUIRE(lexicon.endswith("on", true) == 5);
}

// 4. Nα εμφανίζει το πλήθος και εφόσον ο χρήστης επιθυμεί όλες τις λέξεις 
// που περιέχουν μια ακολουθία γραμμάτων που θα δίνει ο χρήστης 
// τόσες συνεχόμενες φορές όσες θα δίνει ο χρήστης.
TEST_CASE("Get words that contain 'ti' in them 2 times")
{
    Lexicon lexicon("Test_4.txt");

    std::cout << "Get words that contain 'ti' in them 2 times" << std::endl;
    REQUIRE(lexicon.substr_count("ti", 2, true) == 10);
}

// 5. Nα εμφανίζει το πλήθος και εφόσον ο χρήστης επιθυμεί όλες τις λέξεις 
// που περιέχουν σε θέσεις που θα επιλέγει ο χρήστης συγκεκριμένα γράμματα 
//(για παράδειγμα ba-a-a σημαίνει ότι αναζητείται οποιαδήποτε λέξη 
// που περιέχει σε οποιοδήποτε θέση τη σειρά γραμμάτων ba-a-a με το - να σημαίνει οποιοδήποτε γράμμα, 
// οπότε τέτοιες λέξεις είναι οι bahamas και banana).
TEST_CASE("Get words that contain the sequence 'ba-a-a', where '-' is any letter")
{
    Lexicon lexicon("Test_5.txt");

    std::cout << "Get words that contain the sequence 'ba-a-a', where '-' is any letter" << std::endl;
    REQUIRE(lexicon.char_regex("ba-a-a", true) == 1);
}