import py_trees
import time
class Pong(py_trees.behaviour.Behaviour):
    """
    Simple counting behaviour that facilitates the demonstration of a behaviour in
    the demo behaviours lifecycle program.

    * Increments a counter from zero at each tick
    * Finishes with success if the counter reaches three
    * Resets the counter in the initialise() method.
    """
    def __init__(self, name="Counter"):
        """
        Default construction.
        """
        super(Pong, self).__init__(name)
        self.blackboard = self.attach_blackboard_client(name="Pong")
        self.blackboard.register_key(key="count", access=py_trees.common.Access.READ)

    def setup(self):
        """
        No delayed initialisation required for this example.
        """
        # self.logger.debug("%s.setup()" % (self.__class__.__name__))
        print("{} says: Ponger is ready".format(self.name))

    def initialise(self):
        """
        Reset a counter variable.
        """
        # self.logger.debug("%s.initialise()" % (self.__class__.__name__))

    def update(self):
        """
        Increment the counter and decide upon a new status result for the behaviour.
        """
        # new_status = py_trees.common.Status.SUCCESS if self.counter == 3 else py_trees.common.Status.RUNNING
        # if new_status == py_trees.common.Status.SUCCESS:
        #     self.feedback_message = "counting...{0} - phew, thats enough for today".format(self.counter)
        # else:
        #     self.feedback_message = "still counting"
        # self.logger.debug("%s.update()[%s->%s][%s]" % (self.__class__.__name__, self.status, new_status, self.feedback_message))
        print("{} says: Ping received {}".format(self.name, self.blackboard.count))
        time.sleep(0.5)
        print("{} says: Pong sent {}".format(self.name, self.blackboard.count))
        return py_trees.common.Status.SUCCESS

    def terminate(self, new_status):
        """
        Nothing to clean up in this example.
        """
        # self.logger.debug("%s.terminate()[%s->%s]" % (self.__class__.__name__, self.status, new_status))
