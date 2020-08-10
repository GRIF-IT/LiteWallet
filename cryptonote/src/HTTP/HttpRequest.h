// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <iostream>
#include <map>
#include <string>
#include "android.h"

namespace CryptoNote {
  class HttpRequest {
  public:
    typedef std::map<std::string, std::string> Headers;

    const std::string& getMethod() const;
    const std::string& getUrl() const;
    const Headers& getHeaders() const;
    const std::string& getBody() const;

    void addHeader(const std::string& name, const std::string& value);
    void setBody(const std::string& b);
    void setUrl(const std::string& uri);

  private:
    friend class HttpParser;

    std::string method;
    std::string url;
    Headers headers;
    std::string body;

    friend std::ostream& operator<<(std::ostream& os, const HttpRequest& resp);
    std::ostream& printHttpRequest(std::ostream& os) const;
  };

  inline std::ostream& operator<<(std::ostream& os, const HttpRequest& resp) {
    return resp.printHttpRequest(os);
  }
}