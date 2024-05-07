#include <iostream>
#include <vector>
#include <algorithm> 
#include <list>
#include <string>
using namespace std;

/* 使用 iterator，unique，sort，erase等函数对容器进行操作
分别在读取输入后、调用 unique后以及调用erase后打印vector的内容。
*/
template <typename Sequence>
auto println(const Sequence& seq) -> ostream& {
    for (auto const& elem : seq) {
        cout << elem << " "; 
    }
    return cout << endl;
}

/*
std::unique(vs.begin(), vs.end())：这个调用将 vs 中所有连续重复的元素压缩，
只保留一个，并返回一个新的迭代器 new_end，指向压缩后容器中"新"末尾的下一个位置。
i.e. {1,2,1,3,5,2} -> {1,2,3,5,1,2}  new_end -> 1 after 5
即，从 new_end 到 vs.end() 范围内的元素现在是未定义的状态，通常包含重复数据的副本。*/
auto eliminateDuplicate(vector<string>& vec) {
    sort(vec.begin(), vec.end());
    cout << "after sort: ";
    println(vec);

    auto new_end = unique(vec.begin(), vec.end());
    cout << "after unique: ";
    println(vec);

    vec.erase(new_end, vec.end());  // delete from new_end to vec.end()

    return vec;
}

int main() {
    vector<string> vs = {"a", "v", "a", "s", "v", "a", "a"};
    cout << "Original: ";
    println(vs);

    println(eliminateDuplicate(vs));

    return 0;
}
/*
Original: a v a s v a a 
after sort: a a a a s v v 
after uniquea s v a   v 
a s v 
*/

