#pragma once

#include "test_runner.h"
//Testing functions:
void TestAddSynonyms()
{
    {
        Synonyms empty;
        AddSynonyms(empty, "a", "b");
        const Synonyms expected = {
            {"a", {"b"}},
            {"b", {"a"}}

        };
        AssertEqual(empty, expected, "First empty test for TestAddSynonyms");
    }
    {
        Synonyms synonyms = {
            {"a", {"b"}},
            {"b", {"a", "c"}},
            {"c", {"b"}}

        };

        AddSynonyms(synonyms, "a", "c");
        const Synonyms expected = {
            {"a", {"b", "c"}},
            {"b", {"a", "c"}},
            {"c", {"b", "a"}}

        };
        AssertEqual(synonyms, expected, "First NON-empty test for TestAddSynonyms");
    }
}

void TestGetSynonymsCount()
{
    {
        Synonyms empty;
        AssertEqual(GetSynonymsCount(empty, "a"), 0u, "Empty test TestGetSynonymsCount");
    }
    {
        Synonyms synonyms = {
            {"a", {"b"}},
            {"b", {"a", "c"}},
            {"c", {"b"}}

        };
        AssertEqual(GetSynonymsCount(synonyms, "b"), 2u, "First non- empty test TestGetSynonymsCount");
        AssertEqual(GetSynonymsCount(synonyms, "a"), 1u, "Second non- empty test TestGetSynonymsCount");
        AssertEqual(GetSynonymsCount(synonyms, "z"), 0u, "Third non- empty test TestGetSynonymsCount");
    }
}

void TestAreSynonyms()
{
    {
        Synonyms empty;
        Assert(!AreSynonyms(empty, "a", "b"), "First empty test for TestAreSynonyms");
        Assert(!AreSynonyms(empty, "b", "a"), "Second empty test for TestAreSynonyms");
    }
    {
        Synonyms synonyms = {
            {"a", {"b"}},
            {"b", {"a", "c"}},
            {"c", {"b"}}

        };
        Assert(AreSynonyms(synonyms, "a", "b"), "First NON-empty test for TestAreSynonyms");
        Assert(AreSynonyms(synonyms, "b", "c"), "Second NON-empty test for TestAreSynonyms");
        Assert(!AreSynonyms(synonyms, "c", "a"), "Third NON-empty test for TestAreSynonyms");
    }
}

//All test started here:

void TestAll()
{
    TestRunner tr;
    tr.RunTest(TestAddSynonyms, "TestAddSynonyms");
    tr.RunTest(TestGetSynonymsCount, "TestGetSynonymsCount");
    tr.RunTest(TestAreSynonyms, "TestAreSynonyms");
}