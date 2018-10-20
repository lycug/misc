#include "cell_mgr.h"

void cell_mgr::update()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			update_cell(x, y);			
		}
	}
	m_cells.swap(m_back);
}

void cell_mgr::update_cell(int x, int y)
{
	auto& cell = get_cell(x, y);
	auto& back = get_back(x, y);
	int neighbor_count = 0;

	neighbor_count += get_cell(x - 1, y - 1).alive ? 1 : 0;
	neighbor_count += get_cell(x - 1, y).alive ? 1 : 0;
	neighbor_count += get_cell(x - 1, y + 1).alive ? 1 : 0;
	neighbor_count += get_cell(x, y + 1).alive ? 1 : 0;

	neighbor_count += get_cell(x + 1, y + 1).alive ? 1 : 0;
	neighbor_count += get_cell(x + 1, y).alive ? 1 : 0;
	neighbor_count += get_cell(x + 1, y - 1).alive ? 1 : 0;
	neighbor_count += get_cell(x, y - 1).alive ? 1 : 0;

	/*
	1�� ���һ��ϸ����Χ��3��ϸ��Ϊ����һ��ϸ����Χ����8��ϸ���������ϸ��Ϊ��������ϸ����ԭ��Ϊ������תΪ������ԭ��Ϊ�����򱣳ֲ��䣩 ��
	2�� ���һ��ϸ����Χ��2��ϸ��Ϊ�������ϸ��������״̬���ֲ��䣻
	3�� ����������£���ϸ��Ϊ��������ϸ����ԭ��Ϊ������תΪ������ԭ��Ϊ�����򱣳ֲ��䣩
	*/

	if (neighbor_count == 3)
	{
		back.alive = true;
	}
	else if (neighbor_count == 2)
	{
		back.alive = cell.alive;
	}
	else
	{
		back.alive = false;
	}
}
