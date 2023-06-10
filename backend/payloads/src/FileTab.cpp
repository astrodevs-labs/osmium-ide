/*
** payload-library, 2022
** FileTab.cpp by Leon
*/

#include "FileTab.hpp"

std::string payloads::FileTab::getContent() { return _content; }

std::string payloads::FileTab::getEncodedContent() { return _encodedContent; }

std::string payloads::FileTab::getFilename() { return _filename; }

std::string payloads::FileTab::getpath() { return _path; }

void payloads::FileTab::setContent(std::string content) { _content = content; }

void payloads::FileTab::setEncodedContent(std::string encodedContent) { _encodedContent = encodedContent; }

void payloads::FileTab::setFilename(std::string filename) { _filename = filename; }

void payloads::FileTab::setpath(std::string path) { _path = path; }
