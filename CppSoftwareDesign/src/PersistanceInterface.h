#pragma once

class PersistanceInterface
{
public:
	virtual ~PersistanceInterface() = default;

	bool read() const
	{
		return do_read();
	}

	bool write()
	{
		return do_write();
	}

private:
	virtual bool do_read() const = 0;
	virtual bool do_write() = 0;
};


PersistanceInterface* get_persistance_interface();

void set_persistance_interface(PersistanceInterface* persistance);

extern PersistanceInterface* instance;
