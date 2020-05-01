#pragma once
class Resource {
	
private:
	std::string root;
	
public:
	virtual bool create(const std::string & file) = 0;
	inline const std::string & getRoot();
};