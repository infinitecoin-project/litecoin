Infinitecoin Core integration/staging tree
=====================================

https://infinitecoin.com

What is Infinitecoin?
----------------

Infinitecoin is an experimental new digital currency that enables instant payments to
anyone, anywhere in the world. Infinitecoin uses peer-to-peer technology to operate
with no central authority: managing transactions and issuing money are carried
out collectively by the network. Infinitecoin Core is the name of open source
software which enables the use of this currency.

Infinitecoin is scale version of Bitcoin using Litecoin scrypt as a proof-of-work algorithm.

 - 30 second block targets
 - subsidy halves in 86400 blocks (~1 month)
 - ~90600 million total coins
 - 524288 coins per block
 - 120 blocks to retarget difficulty


License
-------

Infinitecoin Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `0.12` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/infinitecoin-project/infinitecoin/tags) are created
regularly to indicate new official, stable release versions of Bitcoin Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](/doc/unit-tests.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`

There are also [regression and integration tests](/qa) of the RPC interface, written
in Python, that are run automatically on the build server.
These tests can be run with: `qa/pull-tester/rpc-tests.py`

The Travis CI system makes sure that every pull request is built for Windows
and Linux, OSX, and that unit and sanity tests are automatically run.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

Translations
------------

Changes to translations as well as new translations can be submitted to
[Github](https://github.com/infinitecoin-project/infinitecoin/pulls).

Reference bitcoin and litecoin translations are periodically pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.
