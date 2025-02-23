#pragma once
#include "PersistanceInterface.h"
#include <iostream>

class Database : public PersistanceInterface
{
public:

	Database() {}
	Database(Database const&) = delete;
	Database& operator=(Database const&) = delete;
	Database(Database&&) = delete;
	Database& operator=(Database&&) = delete;

private:
	bool do_read() const override
	{
		return true;
	}

	bool do_write() override
	{
		return true;
	}

};