class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def create_binary_tree(descriptions):
    nodes = {}
    has_parent = {}

    for desc in descriptions:
        parent_val, child_val, is_left = desc
        if parent_val not in nodes:
            nodes[parent_val] = TreeNode(parent_val)
        if child_val not in nodes:
            nodes[child_val] = TreeNode(child_val)
        if is_left:
            nodes[parent_val].left = nodes[child_val]
        else:
            nodes[parent_val].right = nodes[child_val]
        has_parent[child_val] = True

    root = None
    for node_val in nodes:
        if node_val not in has_parent:
            root = nodes[node_val]
            break

    return root
