#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;

int main(){
    CURL *image;
    CURLcode imgresult;
    FILE *fp;
    string htmlFilename("GoogleImages/google.txt");
    image = curl_easy_init();
    if( image ){
        // Open file
        fp = fopen(htmlFilename.c_str(), "wb");
        if( fp == NULL ) cout << "File cannot be opened";
        string userSearch;

//        cout << "Enter your desired search: ";
//        cin >> userSearch;

        curl_easy_setopt(image, CURLOPT_URL, "https://www.google.com/search?q=mountain+skiing+banff&tbm=isch&ved=2ahUKEwj3ktrr78zzAhUvrXIEHX88ADMQ2-cCegQIABAA&oq=mountain+skiing+banff&gs_lcp=CgNpbWcQAzIGCAAQCBAeOgcIIxDvAxAnOgcIABCxAxBDOgQIABBDOggIABCABBCxAzoFCAAQgAQ6BAgAEB5Q7FZY1IoBYJ-NAWgAcAB4AIABnAGIAcwKkgEEMTMuMpgBAKABAaoBC2d3cy13aXotaW1nwAEB&sclient=img&ei=SbFpYbfKOa_aytMP__iAmAM&bih=986&biw=1800#imgrc=n5JKIsdcQl1RsM");
        curl_easy_setopt(image, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(image, CURLOPT_WRITEDATA, fp);



//        string line;
//        vector<string> splitLine;
//        if (fileIn.fail()) {
//            throw FileException("File cannot be read.");
//        }
//        while (getline(fileIn, line))
//            // Private method split splits the string into three words and adds them to the attributes
//            // firstWords, secondsWords, and thirdWords. The deliminator is "\t"
//            split(line, "\t");
//        fileIn.close();


        // Grab image
        imgresult = curl_easy_perform(image);
        if( imgresult ){
            cout << "Cannot grab the image!n";
        }

        ifstream htmlFile(htmlFilename);
        if (htmlFile.fail()) {
            cout << "File opening failed." << endl;
            return 0;
        }

        string line;

        getline(htmlFile, line);

        cout << line << endl;

        int startIndex(line.find("<img src=\""));
        int endIndex(line.find( '\"', startIndex));
        string imageURL(line.substr(startIndex, endIndex - startIndex));

        cout << imageURL << endl;
//        int startIndex = 0, endIndex = line.find(deliminator); // startIndex and endIndex of each individual word
//        while (endIndex != -1) { // While the next " " is found (.find returns -1 when not found)
//            splitString.push_back(line.substr(startIndex, endIndex - startIndex)); // Push the word onto splitString
//            startIndex = endIndex + deliminator.length(); // new startIndex is the endIndex + the length of " " (which is one)
//            endIndex = line.find(deliminator, startIndex); // Search again for " ", ending when
//        }
//        // When you can't find another space there is still another word in the line. Push that word to splitString.
//        splitString.push_back(line.substr(startIndex, endIndex - startIndex));


//        stringstream s;
//        s << htmlFile.rdbuf();
//
//        cout << s.str() << endl;

    }

// Clean up the resources
    curl_easy_cleanup(image);
// Close the file
    fclose(fp);
    return 0;
}

//https://www.snowmagazine.com/images/features/top-tens/10-best-ski-resorts-in-canada.jpg