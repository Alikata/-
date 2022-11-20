#include <iostream>
#include "gtest/gtest.h"
#include "string_view.h"

class Test_1 : public ::testing::Test
{
protected:
        void SetUp()
        {
        }
        void TearDown()
        {
        }
};

TEST_F(Test_1, test_string_view_empty_size)
{
	char text[] = "hello, world!";
	string_view my_view(text);
	std::string_view view(text);
	ASSERT_EQ(my_view.empty(), view.empty());
	ASSERT_EQ(my_view.size(), view.size());
        char text1[] = "";
        string_view my_view1(text1);
        std::string_view view1(text1);
        ASSERT_EQ(my_view1.empty(), view1.empty());
        ASSERT_EQ(my_view1.size(), view1.size());

}

TEST_F(Test_1, test_string_view_start_end)
{
	char text[] = "hello, world!";
	string_view my_view(text);
	std::string_view view(text);
	char stext[] = "hello";
	char etext[] = "world!";
	string_view smy_view(stext);
        std::string_view sview(stext);
	string_view emy_view(etext);
        std::string_view eview(etext);
	ASSERT_EQ(view.starts_with("ell"), my_view.starts_with("ell"));
        ASSERT_EQ(view.ends_with("hs"), my_view.ends_with("hs"));
	ASSERT_EQ(view.ends_with("ld!"), my_view.ends_with("ld!"));
	ASSERT_EQ(view.starts_with('h'), my_view.starts_with('h'));
	ASSERT_EQ(view.starts_with('l'), my_view.starts_with('l'));
        ASSERT_EQ(view.ends_with('h'), my_view.ends_with('h'));
        ASSERT_EQ(view.ends_with('!'), my_view.ends_with('!'));
        ASSERT_EQ(view.starts_with(sview), my_view.starts_with(smy_view));
        ASSERT_EQ(view.starts_with(eview), my_view.starts_with(emy_view));
        ASSERT_EQ(view.ends_with(sview), my_view.ends_with(smy_view));
	ASSERT_EQ(view.ends_with('!'), my_view.ends_with('!'));
}

TEST_F(Test_1, test_string_view_operator)
{
        char text[] = "hello, world!";
        string_view my_view(text);
        std::string_view view(text);
        ASSERT_EQ(view[3], my_view[3]);
        ASSERT_EQ(view[0], my_view[0]);

}

TEST_F(Test_1, test_string_view_create)
{
        char text[] = "hello, world!";
        string_view my_view(text);
        std::string_view view(text);
	for (size_t i = 0; i < my_view.size(); i++){
                ASSERT_EQ(my_view[i], view[i]);
        }
	string_view my_view_new(my_view);
        std::string_view view_new(view);
        for (size_t i = 0; i < my_view_new.size(); i++){
                ASSERT_EQ(my_view_new[i], view_new[i]);
        }
        string_view my_views(text, 5);
        std::string_view views(text, 5);
        for (size_t i = 0; i < my_views.size(); i++){
                ASSERT_EQ(my_views[i], views[i]);
        }
}


TEST_F(Test_1, test_string_view_substr)
{
        char text[] = "hello, world!";
        string_view my_view(text);
        std::string_view view(text);
        string_view my_stext = my_view.substr(3,5);
        std::string_view stext = view.substr(3,5);
	for (size_t i = 0; i < stext.size(); i++){
        	ASSERT_EQ(stext[i], my_stext[i]);
	}

}


TEST_F(Test_1, test_string_view_remove)
{
        char text[] = "hello, world!";
        string_view my_view(text);
        std::string_view view(text);
        my_view.remove_suffix(3);
        view.remove_suffix(3);
        for (size_t i = 0; i < my_view.size(); i++){
                ASSERT_EQ(view[i], my_view[i]);
        }
        my_view.remove_prefix(5);
        view.remove_prefix(5);
        for (size_t i = 0; i < my_view.size(); i++){
                ASSERT_EQ(view[i], my_view[i]);
        }

}


TEST_F(Test_1, test_string_view_out)
{
        char text[] = "hello, world!";
        string_view my_view(text);
        std::string_view view(text);


	testing::internal::CaptureStdout();
	std::cout << my_view << std::endl;
	std::string my_output = testing::internal::GetCapturedStdout();
	testing::internal::CaptureStdout();
	std::cout << view << std::endl;
        std::string output = testing::internal::GetCapturedStdout();
	ASSERT_STREQ(my_output.c_str(), output.c_str());


}

TEST_F(Test_1, test_string_view_eq)
{
        char text[] = "hello, world!";
	char text2[] = "hello, world";
	string_view view2(text2);
        string_view view(text);
	string_view view1(view);

	ASSERT_TRUE(view == view1);
	ASSERT_FALSE(view1 == view2);

}

int main(int argc, char *argv[])
{
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
