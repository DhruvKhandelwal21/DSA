class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<ArrayList<Integer>> graph = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        for(int i=0;i<numCourses;i++){
            graph.add(new ArrayList<>());
        }
        int []indegrees = new int[numCourses];
        for(int i=0;i<prerequisites.length;i++){
            graph.get(prerequisites[i][1]).add(prerequisites[i][0]);
            indegrees[prerequisites[i][0]]++;
        }
        for(int i=0;i<indegrees.length;i++){
            if(indegrees[i]==0) q.offer(i);
        }
        List<Integer> ans = new ArrayList<>();

        while(!q.isEmpty()){
           int temp = q.poll();
           ans.add(temp);
           for(int num : graph.get(temp)){
            indegrees[num]--;
            if(indegrees[num]==0) q.offer(num);
           }
        }
        if(ans.size()<numCourses) return new int[0];
        int sz = ans.size();
        int[] temp = new int[sz];
        for(int i=0;i<sz;i++){
            temp[i] = ans.get(i);
        }
        return temp;
    }
}