### Seeds ###

Utility to generate the seeds.txt list that is compiled into the client
(see [src/chainparamsseeds.h](/src/chainparamsseeds.h) and other utilities in [contrib/seeds](/contrib/seeds)).

The seed compiled into the build is manually created from https://chainz.cryptoid.info/ifc/#!network
(see [contrib/seeds/nodes_main.txt](/contrib/seeds/nodes_main.txt)).

    python generate-seeds.py . > ../../src/chainparamsseeds.h

