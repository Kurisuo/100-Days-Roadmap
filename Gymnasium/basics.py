import gymnasium as gym 

#.make() to create environment
#Optional: render_mode for how the env should be Visualized
env = gym.make("CartPole-v1", render_mode = "human")

#Reset Episode - obs: what the agent sees (Ex: Velocity, Position, ...)
obs, info = env.reset()

print(f"Starting Observation: {obs}")

episode_over = False
total_reward = 0

while not episode_over:
    
    #Get an Action
    action = env.action_space.sample() #Sample gives us a randoma action
    
    #Take the Action
    obs, reward, terminated, truncated, info = env.step(action)
    
    total_reward += reward
    episode_over = terminated or truncated
    
print(f"Episode finished! Total reward: {total_reward}")
env.close()
    
    