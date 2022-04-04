#!/usr/bin/env python
from pydoc import cli
import py_trees
import time
from ping import Ping
from pong import Pong
from isCountHigher import IsCountHigher
##############################################################################
# Main
##############################################################################
def setup_ping():
    ping_sequence = py_trees.composites.Sequence("ping sequence")
    ping_sequence
    return ping_sequence

def setup_pong(name):
    pong_fallback = py_trees.composites.Selector("Pongers")
    countIsHigherReturnFalse = py_trees.decorators.Inverter(
        name="countResultInvert",
        child=IsCountHigher()
    )    
    pong_fallback.add_child(countIsHigherReturnFalse)
    pong_fallback.add_child(Pong(name))
    return pong_fallback

def setup_pongers():
    pong_sequence = py_trees.composites.Sequence("Pongers")
    pong_sequence.add_child(setup_pong("Pong1"))
    pong_sequence.add_child(setup_pong("Pong2"))
    return pong_sequence



def main():
    # py_trees.logging.level = py_trees.logging.Level.DEBUG
    root = py_trees.composites.Sequence("Root")
    root.add_child(Ping())
    root.add_child(setup_pongers())
    root.setup_with_descendants()
    # try:
    #     for unused_i in range(0, 5):
    #         root.tick_once()
    #     print("\n")
    # except KeyboardInterrupt:
    #     print("")
    #     pass
    behaviour_tree = py_trees.trees.BehaviourTree(
        root=root
    )
    try:
        behaviour_tree.tick_tock(
            period_ms=500,
            number_of_iterations=py_trees.trees.CONTINUOUS_TICK_TOCK,
            pre_tick_handler=None,
            post_tick_handler=None
        )
    except KeyboardInterrupt:
        behaviour_tree.interrupt()
    
main()