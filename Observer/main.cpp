#include <iostream>
#include <list>

struct ISubscriber
{
	virtual void notify(const std::string& msg) = 0;
};

struct User : ISubscriber
{
	User(const int userId)
	{
		this->userId = userId;
	}
	/* inform all users when a change is actually made */
	virtual void notify(const std::string& msg) override
	{
		std::cout << "User: " << userId << 
			" received msg: " << msg << std::endl;
	}

private:
	int userId;
};

struct Group
{
	void subscribe(ISubscriber *user)
	{
		users.push_back(user);
	}
	void unsubscribe(ISubscriber* user)
	{
		users.remove(user);
	}

	void notify(const std::string& msg)
	{
		for (auto user : users)
		{
			user->notify(msg);
		}
	}
private:
	std::list<ISubscriber*> users;
};
int main()
{
	auto group = new Group;

	auto user1 = new User(1);
	auto user2 = new User(2);
	auto user3 = new User(3);

	// subscribe users
	group->subscribe(user1);
	group->subscribe(user2);
	group->subscribe(user3);

	group->notify("new msg..");

	// unsubscribe user
	group->unsubscribe(user1);

	group->notify("new msg arrived...");


	return 0;
}