#include <iostream>
using namespace std;

class Media {
protected:
    string title;
    int publication_date;
    int unique_id;
    string publisher;
    bool is_checked_out;

public:
    Media(string t, int pub_date, int id, string pub)
        : title(t), publication_date(pub_date), unique_id(id), publisher(pub), is_checked_out(false) {}

    virtual void display_info() {
        cout << "Title: " << title << "\nPublication Year: " << publication_date
             << "\nUnique ID: " << unique_id << "\nPublisher: " << publisher << endl;
    }

    void check_out() {
        if (!is_checked_out) {
            is_checked_out = true;
            cout << title << " has been checked out." << endl;
        } else {
            cout << title << " is already checked out." << endl;
        }
    }

    void return_item() {
        if (is_checked_out) {
            is_checked_out = false;
            cout << title << " has been returned." << endl;
        } else {
            cout << title << " was not checked out." << endl;
        }
    }

    string get_title() { return title; }
    int get_publication_date() { return publication_date; }
};

class Book : public Media {
    string author;
    string isbn;
    int number_of_pages;

public:
    Book(string t, int pub_date, int id, string pub, string a, string i, int pages)
        : Media(t, pub_date, id, pub), author(a), isbn(i), number_of_pages(pages) {}

    void display_info() override {
        Media::display_info();
        cout << "Author: " << author << "\nISBN: " << isbn
             << "\nPages: " << number_of_pages << endl;
    }

    string get_author() { return author; }
};

class DVD : public Media {
    string director;
    double duration;
    double rating;

public:
    DVD(string t, int pub_date, int id, string pub, string d, double dur, double r)
        : Media(t, pub_date, id, pub), director(d), duration(dur), rating(r) {}

    void display_info() override {
        Media::display_info();
        cout << "Director: " << director << "\nDuration: " << duration
             << " hours\nRating: " << rating << "/10" << endl;
    }
};

class CD : public Media {
    string artist;
    int number_of_tracks;
    string genre;

public:
    CD(string t, int pub_date, int id, string pub, string art, int tracks, string g)
        : Media(t, pub_date, id, pub), artist(art), number_of_tracks(tracks), genre(g) {}

    void display_info() override {
        Media::display_info();
        cout << "Artist: " << artist << "\nTracks: " << number_of_tracks
             << "\nGenre: " << genre << endl;
    }
};

class Library {
public:
    static void search_media(Book books[], int size, string title) {
        for (int i = 0; i < size; i++) {
            if (books[i].get_title() == title) {
                cout << "Book Found:\n";
                books[i].display_info();
                return;
            }
        }
        cout << "Book not found.\n";
    }

    static void search_media(Book books[], int size, int year) {
        for (int i = 0; i < size; i++) {
            if (books[i].get_publication_date() == year) {
                cout << "Books Published in " << year << ":\n";
                books[i].display_info();
            }
        }
    }

    static void search_media(Book books[], int size, string author, bool searchByAuthor) {
        for (int i = 0; i < size; i++) {
            if (searchByAuthor && books[i].get_author() == author) {
                cout << "Books by " << author << ":\n";
                books[i].display_info();
            }
        }
    }
};

int main() {
    Book book1("charlie and the chocolate factory", 1925, 101, "unknown", "roald dhal", "9780743273565", 180);
    DVD dvd1("transformers", 2010, 201, "Warner Bros", "optimus prime", 2.5, 8.8);
    CD cd1("ghulam rasool", 1982, 301, "madni channel", "ghulam rasool", 9, "kid");

    book1.display_info();
    cout << endl;
    dvd1.display_info();
    cout << endl;
    cd1.display_info();
    cout << endl;

    book1.check_out();
    book1.return_item();

    Book books[] = {book1};
    Library::search_media(books, 1, "charlie and the chocolate factory");
    Library::search_media(books, 1, 1925);
    Library::search_media(books, 1, "roald dhal", true);

    return 0;
}
