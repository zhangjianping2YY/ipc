#ifndef CONNECTION_CPP_H
#define CONNECTION_CPP_H

#define CONN_TYPE_ALL 1
#define CONN_TYPE_PID 2
#define CONN_TYPE_SUB 3

#define MAX_MSG_SIZE 1048576


namespace IPC{
  typedef void (*ConnectionCallback)(IPC::Message msg);

  class Connection{
  public:
    Connection(void* ptr_): ptr(ptr_){}
    Connection(char* name, int type, int create=1);
    ~Connection();

    void startAutoDispatch();
    void stopAutoDispatch();
    void setCallback(ConnectionCallback cb);
    ConnectionCallback getCallback();
    void removeCallback();
    void send(Message msg);
    void subscribe(char* subject);
    void removeSubscription(char* subject);
    void close();

  private:
    void* ptr;
  };
}

#endif
