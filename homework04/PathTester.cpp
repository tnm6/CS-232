#include "PathTester.h"
#include <cassert>
#include <iostream>
#include <cstdlib>
using namespace std;

void PathTester::run() const
{
  Path test;

  cout << "Testing Path class" << endl;
  testConstructor(test);
  testFind(test);
  testGetDir(test);
  cout << "Path tests passed" << endl;
}

void PathTester::testConstructor(const Path &test) const
{
  cout << "\tTesting constructor" << endl;

  assert(!test.directories.empty());

  // Tests specific to Nathan's MacBook
  // TODO: add tests for uLab machines
  assert(test.directories.size() == 6);
  assert(test.directories[0].compare("/usr/local/bin") == 0);
  assert(test.directories[1].compare("/usr/local/sbin") == 0);
  assert(test.directories[2].compare("/usr/bin") == 0);
  assert(test.directories[3].compare("/bin") == 0);
  assert(test.directories[4].compare("/usr/sbin") == 0);
  assert(test.directories[5].compare("/sbin") == 0);

  cout << "\tConstructor tests passed" << endl;
}

void PathTester::testFind(const Path &test) const
{
  cout << "\tTesting find()" << endl;

  // Tests specific to Nathan's MacBook
  // TODO: add tests for uLab machines
  assert(test.find("zsh") == 0);
  assert(test.find("snmpdelta") == 2);
  assert(test.find("kill") == 3);
  assert(test.find("klist_cdhashes") == 4);
  assert(test.find("mount_cd9660") == 5);
  assert(test.find("blahblahblah") == -1);

  cout << "\tfind() tests passed" << endl;
}

void PathTester::testGetDir(const Path &test) const
{ 
  cout << "\tTesting getDirectory()" << endl;

  // Tests specific to Nathan's MacBook
  // TODO: add tests for uLab machines
  assert(test.getDirectory(0).compare("/usr/local/bin") == 0);
  assert(test.getDirectory(1).compare("/usr/local/sbin") == 0);
  assert(test.getDirectory(2).compare("/usr/bin") == 0);
  assert(test.getDirectory(3).compare("/bin") == 0);
  assert(test.getDirectory(4).compare("/usr/sbin") == 0);
  assert(test.getDirectory(5).compare("/sbin") == 0);

  try {
    test.getDirectory(6);
    cout << "getDirectory() allowed out of bounds index" << endl;
    exit(-1);
  }
  catch (out_of_range e) { }  // continue

  cout << "\tgetDirectory() tests passed" << endl;
}