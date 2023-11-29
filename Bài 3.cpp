#include <iostream>
#include <vector>
#include <string>

class Media {
protected:
    std::string title;
    double price;

public:
    Media() : title(""), price(0.0) {}

    Media(const std::string& _title, double _price) : title(_title), price(_price) {}

    virtual ~Media() {}

    virtual void inputInfo() {
        std::cout << "Nhap ten phuong tien: ";
        std::cin.ignore(); // Clear the newline character from the input buffer
        std::getline(std::cin, title);

        std::cout << "Nhap gia ban: ";
        std::cin >> price;
    }

    virtual void displayInfo() const {
        std::cout << "Ten: " << title << ", Gia ban: " << price << std::endl;
    }
};

class Book : public Media {
private:
    int pageCount;
    std::string author;

public:
    Book() : Media(), pageCount(0), author("") {}

    Book(const std::string& _title, double _price, int _pageCount, const std::string& _author)
        : Media(_title, _price), pageCount(_pageCount), author(_author) {}

    void inputInfo() override {
        Media::inputInfo(); // Call the base class inputInfo method

        std::cout << "Nhap so trang: ";
        std::cin >> pageCount;

        std::cout << "Nhap ten tac gia: ";
        std::cin.ignore(); // Clear the newline character from the input buffer
        std::getline(std::cin, author);
    }

    void displayInfo() const override {
        Media::displayInfo(); // Call the base class displayInfo method

        std::cout << "So trang: " << pageCount << ", Tac gia: " << author << std::endl;
    }

    // Getter for the book title
    std::string getTitle() const {
        return title;
    }

    // Getter for the author
    std::string getAuthor() const {
        return author;
    }
};

int main() {
    // Nhập thông tin cho một phương tiện truyền thông media
    Media media;
    std::cout << "Nhap thong tin phuong tien truyen thong media:\n";
    media.inputInfo();

    // Hiển thị thông tin của phương tiện media vừa nhập
    std::cout << "\nThong tin phuong tien media:\n";
    media.displayInfo();

    // Nhập thông tin cho n đối tượng BOOK
    int n;
    std::cout << "\nNhap so luong sach: ";
    std::cin >> n;

    std::vector<Book> bookList(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "\nNhap thong tin cho cuon sach thu " << i + 1 << ":\n";
        bookList[i].inputInfo();
    }

    // In ra màn hình thông tin của n đối tượng BOOK
    std::cout << "\nThong tin cac cuon sach:\n";
    for (const auto &book : bookList) {
        book.displayInfo();
        std::cout << "\n";
    }

    // Hiển thị những cuốn sách có tên là "Lap trinh C++" của tác giả "Nguyen Thanh Thuy"
    std::cout << "\nCac cuon sach Lap trinh C++ cua tac gia Nguyen Thanh Thuy:\n";
    for (const auto &book : bookList) {
        if (book.getTitle() == "Lap trinh C++" && book.getAuthor() == "Nguyen Thanh Thuy") {
            book.displayInfo();
            std::cout << "\n";
        }
    }

    return 0;
}
