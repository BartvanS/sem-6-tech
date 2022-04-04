from platform import python_branch
import py_trees

class IsCountHigher(py_trees.behaviour.Behaviour):
    def __init__(self, name="isCountHigher"):
        """
        Default construction.
        """
        super(IsCountHigher, self).__init__(name)
        self.blackboard = self.attach_blackboard_client(name="Ping")
        self.blackboard.register_key(key="count", access=py_trees.common.Access.READ)
        self.prevCount = -1

    def setup(self):
        """
        No delayed initialisation required for this example.
        """

    def initialise(self):
        """
        Reset a variable.
        """

    def update(self):
        """
        Increment the counter and decide upon a new status result for the behaviour.
        """
        if self.blackboard.count > self.prevCount:
            self.prevCount = self.blackboard.count
            return py_trees.common.Status.SUCCESS
        else:
            return py_trees.common.Status.FAILURE

    def terminate(self, new_status):
        """
        Nothing to clean up in this example.
        """
