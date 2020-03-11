#include "PathTester.h"
#include <cassert>
#include <iostream>
using namespace std;

void PathTester::run() const
{
  cout << "Testing Path class" << endl;
  testConstructor();
  testFind();
  testGetDir();
  cout << "Path tests passed" << endl;
}

void PathTester::testConstructor() const
{
  Path test;

  cout << "Testing constructor" << endl;
  // Tests specific to my MacBook
  // TODO: add tests for uLab machines
  assert( !test.directories.empty() );
  assert(test.directories.size() == 6);
  assert(test.directories[0].compare("/usr/local/bin"));
  assert(test.directories[1].compare("/usr/local/sbin"));
  assert(test.directories[2].compare("/usr/bin"));
  assert(test.directories[3].compare("/bin"));
  assert(test.directories[4].compare("/usr/sbin"));
  assert(test.directories[5].compare("/sbin"));

  cout << "Constructor tests passed" << endl;
}

void PathTester::testFind() const
{
  Path test;

  cout << "Testing find()" << endl;

  // Tests specific to Nathan's MacBook
  // TODO: add tests for uLab machines
  assert( test.find("zsh") == 0 );
  assert( test.find("md5") == 1 );
  assert( test.find("snmpdelta") == 2);
  assert( test.find("kill") == 3 );
  assert( test.find("klist_cdhashes") == 4);
  assert( test.find("mount_cd9660") == 5);
  assert( test.find("blahblahblah") == -1);

  cout << "find() tests passed" << endl;
}