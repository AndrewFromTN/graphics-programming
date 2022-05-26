#ifndef QUADTREE_HPP
#define QUADTREE_HPP

#include <vector>
#include <iostream>

#include "Rectangle.hpp"

template <class T>
class Node
{
	public:
		Node(glm::vec3 vect, T* data)
		{
			this->vect = vect;
			this->data = data;
		}
		
		T* data;
		glm::vec3 vect;
};

template <class T>
class Quadtree
{
	private:
		const std::size_t MAX_SIZE = 5;
	
		Quadtree<T>* north_west;
		Quadtree<T>* north_east;
		Quadtree<T>* south_west;
		Quadtree<T>* south_east;
	
		FloatRect location;
		
		bool area_contains_location(const FloatRect &area) const;
		bool location_contains_area(const FloatRect &area) const;

		bool insert(Node<T>* node);
		Node<T>* update_helper(const glm::vec3 &vect, T* node);
		std::vector<Node<T>*> get_contained_nodes(const FloatRect &area) const;

		std::vector<Node<T>*> points;
	public:
		explicit Quadtree(const FloatRect &location);
		Quadtree(const Quadtree &tree);
		Quadtree(Quadtree&&) = default;
		~Quadtree();

		Quadtree& operator=(const Quadtree&) = default;
		Quadtree& operator=(Quadtree&&) = default;

		bool insert(const glm::vec3 &vect, T* new_val);
		bool remove(T* node);
		bool update(const glm::vec3 &vect, T* node);
		std::vector<T*> get_contained_values(const FloatRect &area) const;

};

template <class T>
Quadtree<T>::Quadtree(const FloatRect &location) : location(location)
{
	north_west = nullptr;
	north_east = nullptr;
	south_east = nullptr;
	south_west = nullptr;

	points.reserve(MAX_SIZE);
}

template <class T>
Quadtree<T>::Quadtree(const Quadtree &tree)
{
	tree->north_west = nullptr;
	tree->north_east = nullptr;
	tree->south_west = nullptr;
	tree->south_east = nullptr;
}

template <class T>
bool Quadtree<T>::area_contains_location(const FloatRect &area) const
{
	return (location.position.x >= area.position.x && location.position.y >= area.position.y &&
			location.position.x + location.width <= area.position.x + area.width &&
			location.position.y + location.height <= area.position.y + area.height
		   );
}

template <class T>
bool Quadtree<T>::location_contains_area(const FloatRect &area) const
{
	return (location.position.x <= area.position.x && location.position.y <= area.position.y &&
			location.position.x + location.width >= area.position.x + area.width &&
			location.position.y + location.height >= area.position.y + area.height
		   );
}

template <class T>
bool Quadtree<T>::insert(Node<T>* node)
{
	if (!location.contains(node->vect))
	{
		return false;
	}

	if (points.size() < MAX_SIZE)
	{
		points.push_back(node);

		return true;
	}

	FloatRect tmp(location);
	tmp.width /= 2.0f;
	tmp.height /= 2.0f;

	Quadtree* curr = nullptr;

	if (tmp.contains(node->vect))
	{
		if (north_west != nullptr)
		{
			return north_west->insert(node);
		}

		north_west = new Quadtree(tmp);

		curr = north_west;
	}

	tmp.position.x += tmp.width;
	if (tmp.contains(node->vect))
	{
		if (north_east != nullptr)
		{
			return north_east->insert(node);
		}

		north_east = new Quadtree(tmp);

		curr = north_east;
	}

	tmp.position.y += tmp.height;
	if (tmp.contains(node->vect))
	{
		if (south_east != nullptr)
		{
			return south_east->insert(node);
		}

		south_east = new Quadtree(tmp);

		curr = south_east;
	}

	tmp.position.x -= tmp.width;
	if (tmp.contains(node->vect))
	{
		if (south_west != nullptr)
		{
			return south_west->insert(node);
		}

		south_west = new Quadtree(tmp);

		curr = south_west;
	}

	for (std::size_t i = 0; i < points.size(); ++i)
	{
		if (curr->location.contains(points[i]->vect))
		{
			curr->insert(points[i]->vect, points[i]->data);

			points.erase(points.begin() + i);

			--i;
		}
	}

	return curr->insert(node);
}

template <class T>
bool Quadtree<T>::insert(const glm::vec3 &vect, T* new_val)
{
	if (!location.contains(vect))
	{
		return false;
	}

	if (points.size() < MAX_SIZE)
	{
		Node<T>* new_node = new Node<T>(vect, new_val);

		points.push_back(new_node);

		return true;
	}

	FloatRect tmp(location);
	tmp.width /= 2.0f;
	tmp.height /= 2.0f;

	Quadtree* curr = nullptr;

	if (tmp.contains(vect))
	{
		if (north_west != nullptr)
		{
			return north_west->insert(vect, new_val);
		}

		north_west = new Quadtree(tmp);

		curr = north_west;
	}

	tmp.position.x += tmp.width;
	if (tmp.contains(vect))
	{
		if (north_east != nullptr)
		{
			return north_east->insert(vect, new_val);
		}

		north_east = new Quadtree(tmp);

		curr = north_east;
	}

	tmp.position.y += tmp.height;
	if (tmp.contains(vect))
	{
		if (south_east != nullptr)
		{
			return south_east->insert(vect, new_val);
		}

		south_east = new Quadtree(tmp);

		curr = south_east;
	}

	tmp.position.x -= tmp.width;
	if (tmp.contains(vect))
	{
		if (south_west != nullptr)
		{
			return south_west->insert(vect, new_val);
		}

		south_west = new Quadtree(tmp);

		curr = south_west;
	}

	for (std::size_t i = 0; i < points.size(); ++i)
	{
		if (curr->location.contains(points[i]->vect))
		{
			curr->insert(points[i]);

			points.erase(points.begin() + i);

			--i;
		}
	}

	return curr->insert(vect, new_val);
}

template <class T>
bool Quadtree<T>::remove(T* node)
{
	const auto elem = std::find_if(points.begin(), points.end(), [&node](Node<T>* val)
	{
		return val->data == node;
	});

	if (elem != points.end())
	{
		delete *elem;
		*elem = nullptr;

		points.erase(elem);

		return true;
	}

	if (north_west != nullptr)
	{
		const bool success = north_west->remove(node);

		if (north_west->get_contained_nodes(north_west->location).empty())
		{
			delete north_west;
			north_west = nullptr;
		}

		return success;
	}

	if (north_east != nullptr)
	{
		const bool success = north_east->remove(node);

		if (north_east->get_contained_nodes(north_east->location).empty())
		{
			delete north_east;
			north_east = nullptr;
		}

		return success;
	}

	if (south_east != nullptr)
	{
		const bool success = south_east->remove(node);

		if (south_east->get_contained_nodes(south_east->location).empty())
		{
			delete south_east;
			south_east = nullptr;
		}

		return success;
	}

	if (south_west != nullptr)
	{
		const bool success = south_west->remove(node);

		if (south_west->get_contained_nodes(south_west->location).empty())
		{
			delete south_west;
			south_west = nullptr;
		}

		return success;
	}

	return false;
}

template <class T>
Node<T>* Quadtree<T>::update_helper(const glm::vec3 &vect, T* node)
{
	const auto elem = std::find_if(points.begin(), points.end(), [&node](Node<T>* val)
	{
		return val->data == node;
	});

	if (elem != points.end())
	{
		if (!location.contains(vect))
		{
			auto ret = *elem;

			points.erase(elem);

			return ret;
		}

		(*elem)->data = node;
		(*elem)->vect = vect;

		return nullptr;
	}

	Node<T>* to_insert = nullptr;
	if (north_west != nullptr)
	{
		if ((to_insert = north_west->update_helper(vect, node)) != nullptr)
		{
			insert(to_insert);
			return nullptr;
		}
	}

	if (north_east != nullptr)
	{
		if ((to_insert = north_east->update_helper(vect, node)) != nullptr)
		{
			insert(to_insert);
			return nullptr;
		}
	}

	if (south_east != nullptr)
	{
		if ((to_insert = south_east->update_helper(vect, node)) != nullptr)
		{
			insert(to_insert);
			return nullptr;
		}
	}

	if (south_west != nullptr)
	{
		if ((to_insert = south_west->update_helper(vect, node)) != nullptr)
		{
			insert(to_insert);
			return nullptr;
		}
	}

	return nullptr;
}

template <class T>
bool Quadtree<T>::update(const glm::vec3 &vect, T* node)
{
	// Will this always return true?
	return update_helper(vect, node) == nullptr;
}

template <class T>
std::vector<Node<T>*> Quadtree<T>::get_contained_nodes(const FloatRect &area) const
{
	std::vector<Node<T>*> nodes;

	if (location.intersects(area))
	{
		std::for_each(points.begin(), points.end(), [&](Node<T>* node)
		{
			if (area.contains(node->vect))
			{
				nodes.push_back(node);
			}
		});
	}

	if (north_west != nullptr)
	{
		auto values = north_west->get_contained_nodes(area);

		nodes.reserve(values.size());
		nodes.insert(nodes.end(), values.begin(), values.end());
	}

	if (north_east != nullptr)
	{
		auto values = north_east->get_contained_nodes(area);

		nodes.reserve(values.size());
		nodes.insert(nodes.end(), values.begin(), values.end());
	}

	if (south_east != nullptr)
	{
		auto values = south_east->get_contained_nodes(area);

		nodes.reserve(values.size());
		nodes.insert(nodes.end(), values.begin(), values.end());
	}

	if (south_west != nullptr)
	{
		auto values = south_west->get_contained_nodes(area);

		nodes.reserve(values.size());
		nodes.insert(nodes.end(), values.begin(), values.end());
	}

	return nodes;
}

template <class T>
std::vector<T*> Quadtree<T>::get_contained_values(const FloatRect &area) const
{
	std::vector<Node<T>*> nodes = get_contained_nodes(area);

	std::vector<T*> ret;
	ret.reserve(nodes.size());

	std::for_each(nodes.begin(), nodes.end(), [&nodes, &ret](Node<T>* node)
	{
		ret.push_back(node->data);
	});

	return ret;
}

template <class T>
Quadtree<T>::~Quadtree()
{
	std::for_each(points.begin(), points.end(), [&](Node<T>* node)
	{
		delete node;
		node = nullptr;
	});
	
	if (north_west != nullptr)
	{
		delete north_west;
		north_west = nullptr;
	}

	if (north_east != nullptr)
	{
		delete north_east;
		north_east = nullptr;
	}

	if (south_east != nullptr)
	{
		delete south_east;
		south_east = nullptr;
	}

	if (south_west != nullptr)
	{
		delete south_west;
		south_west = nullptr;
	}
}

#endif